#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector < vector<int> > v;

int main()
{
    int n; cin >> n;
    int p = 1, q = 0;
    while (p < n) p += p, q++;
    v.resize(q);
    cout << q << endl;
    for (int i = 0; i < q; i++)
        for (int j = 0; j < n; j++)
            if (((j >> i) & 1) == 0) v[i].push_back(j + 1);

    for (int i = 0; i < q; i++)
    {
        cout << v[i].size() << " ";
        for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
        cout << endl;
    }
}