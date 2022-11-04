#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

bool ok(ll x)
{
    bool res=false;

    while (x>0)
    {
        res|=((x%10)==7);
        x/=10;
    }

    return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll x , h , m;
	cin>>x>>h>>m;

	ll res=0;

	while (!ok(h) && !ok(m))
    {
        m-=x;
        res++;

        if (m<0)
        {
            m+=60;
            h--;
        }

        if (h<0)
        {
            h+=24;
        }
    }

    cout<<res;
}