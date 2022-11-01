#include <iostream>
#include <vector>

using namespace std;

struct vec {
	int x, y, z;
	void read() {
		cin >> x >> y >> z;
	}
};
int main() {
	vec vasya, cube;
	vasya.read(), cube.read();
	vector <int> a(6);
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	int sum = 0;
	if (vasya.y < 0) sum += a[0];
	if (vasya.y > cube.y) sum += a[1];
	if (vasya.z < 0) sum += a[2];
	if (vasya.z > cube.z) sum += a[3];
	if (vasya.x < 0) sum += a[4];
	if (vasya.x > cube.x) sum += a[5];
	cout << sum;
	return 0;
}