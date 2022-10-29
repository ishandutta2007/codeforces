#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

int n, m, k, j, o, l, r;
string s,d;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d",&n);
	//cout << 1;
	for (int i = 0; i < n; i++)
    {
        char c;
        //cout << 1;
        scanf(" %c",&c);
        if (c=='+')
        {
            int x, y;
            scanf("%d %d",&x,&y);
            if (x<y) swap(x,y);
            l=max(l,x),r=max(r,y);
        } else
        {
            int x, y;
            scanf("%d %d",&x,&y);
            if (x<y) swap(x,y);
            //cout << x << " " << y << "\n";
            if (l<=x && r<=y) printf("YES\n"); else printf("NO\n");
        }
    }
    return 0;
}