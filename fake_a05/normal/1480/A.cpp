#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
#define endl '\n'


#define int long long

int tc;
string s;

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while(tc--)
	{
		cin >> s;
		loop(i, 0, (int) s.size() - 1)
		{
			if(i & 1)
			{
				rloop(c, 25, 0)
				{
					if(s[i] - 'a' != c) 
					{
						s[i] = char (c + 'a');
						break;
					}
				}
			}
			else
			{
				loop(c, 0, 25)
				{
					if(s[i] - 'a' != c)
					{
						s[i] = char(c + 'a');
						break;
					}
				}
			}
		}
		cout << s << endl;
	}
}