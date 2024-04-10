#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#define fr(a,b,c) for(a=b;a<=c;a++)
#define frr(a,b,c) for(a=b;a>=c;a--)
#define rp(a,b,c) for(a=b;a<c;a++)
#define rpp(a,b,c) for(a=b;a>c;a--)
#define maxn 100010
using namespace std;
typedef long long ll;

int n;
string s;

int main()
{
    cin >> n;
    while (n--)
    {
         cin >> s;
         int l=s.length();
         if (l>10) cout << s[0] << l-2 << s[l-1] << endl;
         else cout << s << endl; 
    }   
    //system("pause");
    return 0;
}