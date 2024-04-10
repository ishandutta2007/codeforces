#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<utility>
#include<set>
#include<sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

int a[4][111];

int main()
{
	int n,i,j;
	cin >> n;
   if (n==1)
   {
       fr(i,0,3) if (i<2) cout << 'a' << endl; else cout << 'b' << endl; return 0;
   }
   if (n%2==0)
	{
		fr(i,0,n/2-1) a[0][i*2]=a[0][i*2+1]=a[3][i*2]=a[3][i*2+1]=(i%2?1:0);
		fr(i,0,n/2-2) a[1][i*2+1]=a[1][i*2+2]=(i%2?3:4), a[2][i*2+1]=a[2][i*2+2]=(i%2?5:6);
		a[1][0]=a[2][0]=7;
		a[1][n-1]=a[2][n-1]=8;

	}
	else
	{
       fr(i,0,1) fr(j,0,n/2-1) a[i][j*2]=a[i][j*2+1]=i*2+(j%2);
       fr(i,2,3) fr(j,0,n/2-1) a[i][j*2+1]=a[i][j*2+2]=i*2+(j%2);
       a[0][n-1]=a[1][n-1]=9; a[2][0]=a[3][0]=10;
	}
	fr(i,0,3) { fr(j,0,n-1) cout << char(a[i][j]+97); cout << endl; }
   return 0;
}