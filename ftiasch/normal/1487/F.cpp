#include <bits/stdc++.h>

template <int WIDTH>
static constexpr std::array<uint64_t, WIDTH + 1> precompute_limit_limb() {
  std::array<uint64_t, WIDTH + 1> result{};
  result[0] = 0;
  for (int i = 1; i <= WIDTH; ++i) {
    result[i] = result[i - 1] * 10 + 1;
  }
  return result;
}

struct BigInt {
  static const int WIDTH = 18;
  static const uint64_t MAX = 1000000000000000000ULL;
  static const constexpr std::array<uint64_t, WIDTH + 1> LIMIT_LIMBS =
      precompute_limit_limb<WIDTH>();

  BigInt(int limbs, const std::string &s) : limb(limbs) {
    for (int i = s.size(); i--;) {
      limb[i / WIDTH] = limb[i / WIDTH] * 10 + s[i] - '0';
    }
  }

  int limbs() const { return limb.size(); }

  uint64_t operator[](int i) const { return limb[i]; }

  template <bool tracking = true> void add_one() {
    int i = 0;
    while (i < limbs()) {
      if (limb[i] < MAX - 1) {
        limb[i]++;
        if (tracking) {
          track();
        }
        return;
      }
      limb[i++] = 0;
    }
    assert(i < limbs());
  }

  void sub_one() {
    int i = 0;
    while (i < limbs()) {
      if (limb[i] > 0) {
        limb[i]--;
        return;
      }
      limb[i++] = MAX - 1;
    }
    assert(i < limbs());
  }

  bool operator<=(const BigInt &other) const {
    for (int i = limbs(); i--;) {
      if (limb[i] != other[i]) {
        return limb[i] < other[i];
      }
    }
    return true;
  }

  BigInt &operator-=(const BigInt &one) {
    int borrow = 0;
    for (int i = 0; i < limbs(); ++i) {
      if (limb[i] - borrow >= one[i]) {
        limb[i] -= borrow + one[i];
        borrow = 0;
      } else {
        limb[i] += MAX - borrow - one[i];
        borrow = 1;
      }
    }
    return *this;
  }

  // mod by other, and return the quotient
  int mod(const BigInt &other) {
    int q = 0;
    while (other <= *this) {
      q++;
      *this -= other;
    }
    return q;
  }

  uint64_t limit_limb(int i) const {
    int full = limit / WIDTH;
    if (i < full) {
      return LIMIT_LIMBS[WIDTH];
    }
    if (i == full) {
      return LIMIT_LIMBS[limit % WIDTH];
    }
    return 0;
  }

  void track() {
    while (tracker > 0 && limb[tracker - 1] == limit_limb(tracker - 1)) {
      tracker--;
    }
  }

  void set_limit(int limit_) {
    limit = limit_;
    tracker = limbs();
    track();
  }

  std::string to_string() const {
    std::vector<char> buffer(WIDTH * limbs() + 1);
    for (int i = limbs(); i--;) {
      sprintf(buffer.data(), "%018lu", limb[i]);
    }
    return buffer.data();
  }

  void set_zero() {
    std::fill(limb.begin(), limb.end(), 0);
    set_limit(limit);
  }

  bool limit_reached() const { return tracker == 0; }

  std::vector<uint64_t> limb;
  int limit, tracker;
};

bool operator==(const BigInt &a, const BigInt &b) {
  for (int i = 0; i < a.limbs(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

struct Segment {
  Segment(const BigInt &start_) : start(start_) {}

  void add(int v) { values.push_back(v); }

  int size() const { return values.size(); }

  BigInt start;
  std::vector<int> values;
};

std::vector<Segment> merge(const BigInt &zero,
                           const std::vector<Segment> &segs) {
  std::vector<Segment> result;
  int n = segs.size();
  std::vector<int> cur(n, -1);
  BigInt start = zero;
  Segment seg{zero};
  while (true) {
    int v = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (segs[i].start == start) {
        cur[i] = 0;
      }
      if (0 <= cur[i] && cur[i] < segs[i].size()) {
        v = std::min(v, segs[i].values[cur[i]++]);
      }
    }
    if (v == INT_MAX) {
      if (seg.size()) {
        result.push_back(seg);
      }
      int i = 0;
      while (i < n && ~cur[i]) {
        i++;
      }
      if (i == n) {
        return result;
      }
      start = segs[i].start;
      for (int j = i; j < n; ++j) {
        if (cur[j] == -1 && segs[j].start <= start) {
          start = segs[j].start;
        }
      }
      seg = Segment{start};
    } else {
      seg.add(v);
      start.add_one<false>();
    }
  }
}

int main() {
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  int digits = (s.size() + 1 + BigInt::WIDTH - 1) / BigInt::WIDTH;
  BigInt zero{digits, ""};
  std::vector<Segment> psegs, nsegs;
  {
    Segment seg{BigInt{digits, s}};
    seg.add(0);
    psegs.push_back(seg);
  }
  BigInt pre_one{digits, ""};
  for (int length = s.size() + 1; length > 0; --length) {
    std::vector<Segment> new_psegs, new_nsegs;
    BigInt cur_one{digits, std::string(length, '1')};
    for (auto &&seg : psegs) {
      BigInt r = seg.start;
      int k = r.mod(cur_one);
      Segment new_pseg{r}, new_nseg{r};
      r.set_limit(length);
      r.add_one();
      for (int v : seg.values) {
        new_pseg.add(v + k * length);
        new_nseg.add(v + (k + 1) * length);
        if (r.limit_reached()) {
          new_psegs.push_back(new_pseg);
          new_nsegs.push_back(new_nseg);
          k++;
          r.set_zero();
          new_pseg = new_nseg = Segment{r};
          r.add_one();
        } else {
          r.add_one();
        }
      }
      if (new_pseg.size()) {
        new_psegs.push_back(new_pseg);
        new_nsegs.push_back(new_nseg);
      }
    }
    for (auto &&seg : nsegs) {
      BigInt r = seg.start;
      int k;
      if (r == zero) {
        r = cur_one;
        r.sub_one();
        k = 10;
      } else {
        r.sub_one();
        k = 9 - r.mod(cur_one);
      }
      Segment new_pseg{r}, new_nseg{r};
      r.set_limit(length);
      r.add_one();
      for (int v : seg.values) {
        new_nseg.add(v + k * length);
        new_pseg.add(v + (k + 1) * length);
        if (r.limit_reached()) {
          new_psegs.push_back(new_pseg);
          new_nsegs.push_back(new_nseg);
          k--;
          r.set_zero();
          new_pseg = new_nseg = Segment{r};
          r.add_one();
        } else {
          r.add_one();
        }
      }
      if (new_pseg.size()) {
        new_psegs.push_back(new_pseg);
        new_nsegs.push_back(new_nseg);
      }
    }
    psegs = merge(zero, new_psegs);
    nsegs = merge(zero, new_nsegs);
    // printf("length=%d\n", length);
    // puts("POS_PRE");
    // for (auto &&seg : new_psegs) {
    //   printf("\tstart=%s values ", seg.start.to_string().c_str());
    //   for (int v : seg.values) {
    //     printf("%d ", v);
    //   }
    //   puts("");
    // }
    // puts("POS_POST");
    // for (auto &&seg : psegs) {
    //   printf("\tstart=%s values ", seg.start.to_string().c_str());
    //   for (int v : seg.values) {
    //     printf("%d ", v);
    //   }
    //   puts("");
    // }
    // puts("NEG_PRE");
    // for (auto &&seg : new_nsegs) {
    //   printf("\tstart=%s values ", seg.start.to_string().c_str());
    //   for (int v : seg.values) {
    //     printf("%d ", v);
    //   }
    //   puts("");
    // }
    // puts("NEG_POST");
    // for (auto &&seg : nsegs) {
    //   printf("\tstart=%s values ", seg.start.to_string().c_str());
    //   for (int v : seg.values) {
    //     printf("%d ", v);
    //   }
    //   puts("");
    // }
  }
  assert(psegs.size());
  assert(psegs[0].start == zero);
  printf("%d\n", psegs[0].values[0]);
}