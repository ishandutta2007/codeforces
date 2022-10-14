import std.stdio : readln, writeln;

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
  import core.stdc.limits : INT_MAX;
  import std.algorithm : max, min, fill;

  IO io;
  int T = io.readInt;
  while (T--) {
    int n = io.readInt;
    int m = io.readInt;
    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
      a[i] = io.readInt;
    }
    bool[] gap = new bool[n - 1];
    fill(gap, true);
    for (int i = 0; i < m; ++i) {
      gap[io.readInt - 1] = false;
    }
    int[] suffixMin = new int[n + 1];
    suffixMin[n] = INT_MAX;
    for (int i = n; i--;) {
      suffixMin[i] = min(a[i], suffixMin[i + 1]);
    }
    int prefixMax = 0;
    bool ok = true;
    for (int i = 0; i + 1 < n; ++i) {
      prefixMax = max(prefixMax, a[i]);
      ok &= !gap[i] || prefixMax <= suffixMin[i + 1];
    }
    writeln(ok ? "YES" : "NO");
  }
}