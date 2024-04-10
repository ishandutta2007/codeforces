// author: erray
#include <bits/stdc++.h>
 
using namespace std;
template<typename A, typename B> string to_string(const pair<A, B>& p);
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t);
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& c) {
  return string("'") + c + "'";
}

string to_string(const char *c) {
  return to_string(string(c));
}

string to_string(const bool& b) {
  return (b ? "true" : "false");
}

string to_string(const vector<bool>& v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<size_t T> string to_string(const bitset<T>& bs) {
  return bs.to_string();
}

template<typename T> string to_string(queue<T> q) {
  string res = "{";
  size_t sz = q.size();
  while (sz--) {
    T cur = q.front();
    q.pop();
    q.push(cur);
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T, class C> string to_string(priority_queue<T, vector<T>, C> pq) {
  vector<T> tmp;
  string res = "{";
  while (!pq.empty()) {
    T cur = pq.top();
    pq.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
    tmp.push_back(cur);
  }
  for (auto el : tmp) {
    pq.push(el);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(const T& v) {
  string res = "{";
  for (auto &el : v) {
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(el);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(const pair<A, B>& p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ')';
}
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ')';
}

void debug_out(int size, bool first, string name) {
  vector<string> tmp = {name};
  vector<int> tmp2 = {size, first};
  cerr << endl;
}

constexpr int buffer_size = 255;

template<typename Head, typename... Tail> void debug_out(int size, bool first, string name, Head H, Tail... T) {
  string tmp;
  int off = 0;
  while ((!name.empty() && name[0] != ',') || off != 0) {
    tmp += name[0];
    name.erase(name.begin());
    char c = tmp.back();
    if (c == '{' || c == '(') {
      ++off;
    } else if (c == '}' || c == ')'){
      --off;
    }
  }
  if (!name.empty()) {
    name.erase(name.begin());
  }
  if (tmp[0] == ' ') {
    tmp.erase(tmp.begin());
  }

  string buff = to_string(H);
  if ((int) buff.size() + size + (int) tmp.size() > buffer_size - 5 && !first) {
    cerr << '\n';
    size = 0;
  }
  cerr << '[' << tmp << ": " << buff << "] ";
  debug_out(((int) buff.size() + size + (int) tmp.size() + 5) % buffer_size, false, name, T...);
}

#ifdef DEBUG
#define debug(...) cerr << "-> ", debug_out(3, true, string(#__VA_ARGS__), __VA_ARGS__)
#define here cerr << "-> " << __LINE__ << endl
#else
#define debug(...) void(37)
#define here void(37)
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = int(s.size());      
    debug(s);
    array<int, 26> ct = {};
    for (auto c : s) {
      ++ct[c - 'a'];
    }

    if ((*max_element(ct.begin(), ct.end())) == n) {
      cout << s << '\n';
      // all same
      continue;
    }


    {
      int p = 0;
      while (p < 26 && ct[p] != 1) {
        ++p;
      }
      if (p != 26) {
        int np = 0;
        while (s[np] != p + 'a') {
          ++np;
        } 
        swap(s[0], s[np]);
        sort(s.begin() + 1, s.end());
        cout << s << '\n';    
        continue;
        //one char
      }
    }

    debug("hi");
    
    int first = 0;
    while (ct[first] == 0) {
      ++first;
    }

    bool can_two = false;
    {
      int first_left = ct[first] - 2;
      int left = n - 2 - first_left;
      if (left >= first_left) {
        can_two = true;
      }
    }

    debug("hi");
    if (can_two) {
      debug("can two");
      string left;
      for (auto c : s) {
        if (c != 'a' + first) {
          left += c;
        }
      }
      sort(left.begin(), left.end());
      int left_first = ct[first] - 2;
      string res(2, 'a' + first);
      for (auto c : left) {
        res += c;
        if (left_first > 0) {
          --left_first;
          res += 'a' + first;
        }
      } 
      cout << res << '\n';
      continue;
      //first two can be same
    }

    int second = first + 1;
    while (ct[second] == 0) {
      ++second;
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'a' + first) {
        swap(s[0], s[i]);
      } else if (s[i] == 'a' + second) {
        swap(s[1], s[i]);
      }
    }

    sort(s.begin() + 2, s.end());
    if (ct[second] + ct[first] == n) {
      reverse(s.begin() + 2, s.end());
      cout << s << '\n';
      debug("two char");
      continue;
      //string is from just two chars
    }

    int third = second + 1;
    while (ct[third] == 0) {
      ++third;
    }
    s.erase(find(s.begin(), s.end(), 'a' + third));
    s.insert(s.begin() + ct[first] + 1, 'a' + third);
    cout << s << '\n';
    debug("all normal");
    continue;
    //final
  }
}