#include <iostream>
#include <vector>

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

using namespace std;

vector<vector<int>> fights;
int N;

void solve(int a,int b, int number)
{
    if (b-a <= 1) return;
    if (number >= (int)fights.size())
        fights.push_back(vector<int>(N));
    
    int left = (b-a) / 2;
    int mid = a + left;
    forsn(i,a, mid)
        fights[number][i] = 0;
    forsn(i,mid, b)
        fights[number][i] = 1;
    solve(a, mid, number+1);
    solve(mid, b, number+1);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (cin >> N)
    {
        fights.clear();
        solve(0,N, 0);
        cout << fights.size() << endl;
        for (auto &v : fights)
        {
            vector<int> ret;
            forn(index, v.size())
            if (v[index])
                ret.push_back(index+1);
            cout << ret.size();
            for (int x : ret)
                cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}