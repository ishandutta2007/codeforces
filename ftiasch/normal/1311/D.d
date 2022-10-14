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

import std.container : Array;
import std.typecons : Tuple, tuple;

const int N = 30000;

Tuple!(int, int)[N] best;
Array!int[N] divisors;

void main() {
  import std.algorithm : min;
  import std.math : abs;

  for (int d = 1; d < N; ++d) {
    for (int n = d; n < N; n += d) {
      divisors[n].insert(d);
    }
  }
  IO io;
  int T = io.readInt;
  while (T--) {
    int a = io.readInt;
    int b = io.readInt;
    int c = io.readInt;
    auto result = tuple(a + b + c, 0, 0, 0);
    for (int z = 1; z < N; ++z) {
      best[z] = tuple(result[0], 0);
      foreach (y; divisors[z]) {
        best[z] = min(best[z], tuple(abs(y - a), y));
      }
    }
    for (int z = 1; z < N; ++z) {
      if (abs(z - c) < result[0]) {
        foreach (y; divisors[z]) {
          result = min(result, tuple(abs(z - c) + abs(y - b) + best[y][0], best[y][1], y, z));
        }
      }
    }
    writeln(result[0]);
    writeln(result[1], " ", result[2], " ", result[3]);
  }
}