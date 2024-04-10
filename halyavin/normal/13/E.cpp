#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

std::vector<uint32_t> map;
struct compressed_jump {
  uint32_t next;
  uint32_t count;
};
std::vector<compressed_jump> fmap;
struct change_event {
  uint32_t start_request;
  uint32_t end_request;
  uint32_t change_cell;
  uint32_t new_value;
};
std::vector<uint32_t> requests;
std::vector<change_event> changes;

uint32_t scratch_idx;
std::vector<uint32_t> scratch_pad;

void direct_execute(const std::vector<uint32_t> &m,
                    std::vector<change_event>::iterator begin,
                    std::vector<change_event>::iterator end) {
  uint32_t idx = ++scratch_idx;
  for (uint32_t v : m) {
    scratch_pad[v] = idx;
  }
  for (auto it = begin; it != end; ++it) {
    for (uint32_t request = it->start_request; request != it->end_request; request++) {
      uint32_t start = requests[request];
      uint32_t count = 0;
      while (fmap[start].next != start) {
        count += fmap[start].count;
        start = fmap[start].next;
      }
      std::cout << (start + 1) << " " << (count + 1) << "\n";
    }
    uint32_t cell = it->change_cell;
    uint32_t start = it->new_value;
    map[cell] = start;
    if (start >= map.size()) {
      fmap[cell].next = cell;
      fmap[cell].count = 0;
    } else {
      uint32_t count = 1;
      while (scratch_pad[start] != idx && start != fmap[start].next) {
        count += fmap[start].count;
        start = fmap[start].next;
      }
      fmap[cell].next = start;
      fmap[cell].count = count;
    }
  }
}

void execute_request(const std::vector<uint32_t> &m,
                     std::vector<change_event>::iterator begin,
                     std::vector<change_event>::iterator end) {
  if (std::distance(begin, end) <= 2) {
    direct_execute(m, begin, end);
    return;
  }
  uint32_t idx = ++scratch_idx;
  for (auto it = begin; it != end; ++it) {
    scratch_pad[it->change_cell] = idx;
  }
  std::vector<uint32_t> m1;
  std::vector<uint32_t> m2;
  for (size_t i = 0; i < m.size(); i++) {
    if (scratch_pad[m[i]] == idx) {
      m2.push_back(m[i]);
    } else {
      m1.push_back(m[i]);
    }
  }
  for (size_t i = m1.size(); i-- > 0;) {
    uint32_t cell = m1[i];
    uint32_t start = fmap[cell].next;
    uint32_t count = fmap[cell].count;
    while (scratch_pad[start] != idx && start != fmap[start].next) {
      count += fmap[start].count;
      start = fmap[start].next;
    }
    fmap[cell].next = start;
    fmap[cell].count = count;
  }
  for (size_t i = m2.size(); i-- > 0;) {
    uint32_t cell = m2[i];
    uint32_t start = fmap[cell].next;
    uint32_t count = fmap[cell].count;
    while (scratch_pad[start] != idx && start != fmap[start].next) {
      count += fmap[start].count;
      start = fmap[start].next;
    }
    fmap[cell].next = start;
    fmap[cell].count = count;
  }
  auto split = begin + std::distance(begin, end) / 2;
  execute_request(m2, begin, split);
  execute_request(m2, split, end);
  for (size_t i = 0; i < m.size(); i++) {
    scratch_pad[m[i]] = idx;
  }
  for (size_t i = m.size(); i-- > 0;) {
    uint32_t cell = m[i];
    uint32_t start = map[cell];
    if (start >= map.size()) {
      fmap[cell].next = cell;
      fmap[cell].count = 0;
    } else {
      uint32_t count = 1;
      while (scratch_pad[start] != idx && fmap[start].next != start) {
        count += fmap[start].count;
        start = fmap[start].next;
      }
      fmap[cell].next = start;
      fmap[cell].count = count;
    }
  }
}

void run(std::istream &in, std::ostream &out) {
  uint32_t n, m;
  in >> n >> m;
  map.resize(n);
  fmap.resize(n);
  for (uint32_t i = 0; i < n; i++) {
    uint32_t offset;
    in >> offset;
    map[i] = i + offset;
    if (i + offset < n) {
      fmap[i].next = i + offset;
      fmap[i].count = 1;
    } else {
      fmap[i].next = i;
      fmap[i].count = 0;
    }
  }
  uint32_t last_request = 0;
  for (size_t i = 0; i < m; i++) {
    int type;
    in >> type;
    if (type == 0) {
      uint32_t change_cell, new_value;
      in >> change_cell >> new_value;
      change_cell--;
      changes.push_back(change_event{last_request, static_cast<uint32_t>(requests.size()), change_cell, change_cell + new_value});
      last_request = static_cast<uint32_t>(requests.size());
    } else {
      uint32_t request;
      in >> request;
      request--;
      requests.push_back(request);
    }
  }
  if (last_request < requests.size()) {
    changes.push_back(change_event{last_request, static_cast<uint32_t>(requests.size()), 0, 1});
  }
  std::vector<uint32_t> set;
  for (uint32_t i = 0; i < n; i++) {
    set.push_back(i);
  }
  scratch_pad.resize(n);
  scratch_idx = 0;
  execute_request(set, changes.begin(), changes.end());
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}