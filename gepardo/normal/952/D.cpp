#include <cstdio>
#include <random>
#include <chrono>

using namespace std;

// #5

mt19937 rnd(chrono::system_clock().now().time_since_epoch().count());

int main() {
	puts((rnd() & 1) ? "Even" : "Odd");
}