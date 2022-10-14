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

int solve(int a, int b) {
  if (a == b) {
    return 0;
  }
  if (a < b) {
    return (b & 1) == (a & 1) ? 2 : 1;
  }
  return (b & 1) == (a & 1) ? 1 : 2;
}

void main() {
  IO io;
  int T = io.readInt;
  while (T--) {
    int a = io.readInt;
    int b = io.readInt;
    writeln(solve(a, b));
  }
}