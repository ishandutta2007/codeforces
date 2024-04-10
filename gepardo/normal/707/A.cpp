#include <iostream>

using namespace std;

char get_char()
{
	char c = 0;
	while (c <= ' ') cin >> c;
	return c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	bool was_color = false;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n * m; i++)
	{
		char c = get_char();
		if (c != 'W' && c != 'G' && c != 'B') was_color = true;
	}
	cout << ((was_color) ? "#Color" : "#Black&White");

}