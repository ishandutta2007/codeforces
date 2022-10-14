module C;

import std.stdio : readln, write, writeln;

struct IO {
  import std.conv : to;
  import std.range : empty, front, popFront, split;

  string readToken() {
    while (tokens.empty) {
      tokens = readln.split;
    }
    auto token = tokens.front;
    tokens.popFront;
    return token;
  }

  int readInt() {
    return readToken.to!int;
  }

  string[] tokens;
}

void main() {
  IO io;
  int T = io.readInt;
  while (T--) {
    int n = io.readInt;
    int m = io.readInt;
    string s = io.readToken;
    long[] sum = new long[n];
    sum[n - 1]++;
    for (int i = 0; i < m; ++i) {
      sum[io.readInt - 1]++;
    }
    for (int i = n - 1; i--;) {
      sum[i] += sum[i + 1];
    }
    long[] count = new long[26];
    for (int i = 0; i < n; ++i) {
      count[s[i] - 'a'] += sum[i];
    }
    for (int i = 0; i < 26; ++i) {
      write(count[i], " \n"[i == 25]);
    }
  }
}