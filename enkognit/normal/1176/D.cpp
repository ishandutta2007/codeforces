#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

int n, m, i, j, x, k, ans, kol[3000001];
int z[3000001], pos[3000001];
vector <int> v;
bool t[4000001];
multiset <int> s;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    //ll x, y, z;
    for (int i = 2; i < 3000000; i++)
        if (!t[i])
        {
            v.pb(i);
            pos[i]=v.size();
            z[i]=1;
            if (3000000/i>i)
            {
                ll j=i*i;
                while (j<3000000) t[j]=1, j+=i;
            }
        }else
        {
            for (int j = 2; j <= sqrt(i); j++)
                if (i%j==0) {z[i]=max(i/j,j);break;}
        }

    cin >> n;
    for (int i = 0; i < n*2; i++) {cin >> m;kol[m]++;}

    vector <ll> ans;
    ll o=3000001;
    //cout << z[2088] << "\n";
    while (o>0)
    {
        while (kol[o]<1 && o>0) o--;
        if (o<1) break;
        //cout << *o << "\n";
        //system("pause");
        if (!t[o])
        {
            ans.pb(pos[o]);
            kol[pos[o]]--;
            kol[o]--;
        }else
        {
            //cout << z[*o] << "\n";
            ans.pb(o);
            kol[o]--;
            kol[z[o]]--;
        }
        //cout << s.size() << "\n";
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/