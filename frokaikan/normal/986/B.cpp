#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <fstream>

//#define TEST
#ifdef TEST
std::ifstream myis("input.txt");
std::ofstream myos("output.txt");
#else
std::istream& myis = std::cin;
std::ostream& myos = std::cout;
#endif

using vs = std::vector<size_t>;
using vb = std::vector<bool>;

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n;
	myis >> n;
	vs data(n + 1, 0);
	for (size_t i = 1; i <= n; ++i) {
		myis >> data[i];
	}
	vb already(n + 1, false);
	size_t ans = 0;
	for (size_t i = 1; i <= n; ++i) {
		if (!already[i]) {
			++ans;
			for (size_t j = i; !already[j]; j = data[j]) {
				already[j] = true;
			}
		}
	}
	if (!(ans & 1u)) {
		myos << "Petr" << std::endl;
	} else {
		myos << "Um_nik" << std::endl;
	}
}