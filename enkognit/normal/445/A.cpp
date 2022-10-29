#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mx = 2*1e6;

bool t[101][101];
ll a[101][101],o1[100001],o2[100001];
int l,i,j,n,m,q1,q2;
string s;
char c;

double sqr(int x)
{
 return x*x;
}

void add(int x,int y)
{
 if ((x<1)||(y<1)||(x>n)||(y>m)||(a[x][y]==0)||(t[x][y]==true)) return;
 if ((a[x+1][y]!=2) && (a[x-1][y]!=2) && (a[x][y+1]!=2) && (a[x][y-1]!=2)) a[x][y]=2; else a[x][y]=3;
 q2++;
 o1[q2]=x;
 o2[q2]=y;
 t[x][y]=true;
}

double rast(double x1,double y1,double x2,double y2)
{
 return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

int main()
{
    //freopen("two.in","r",stdin);
    //freopen("two.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (i=1;i<=n;i++)
    {
     cin >> s;
     for (j=0;j<m;j++)
      if (s[j]=='.') a[i][j+1]=1; else
      if (s[j]=='-') {a[i][j+1]=0;t[i][j+1]=true;}
    }
    for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
      if (a[i][j]==1 && t[i][j]==false)
      {
       q1=0;q2=0;
       add(i,j);
       while (q1<q2)
       {
        q1++;
        int x=o1[q1];
        int y=o2[q1];
        add(x+1,y);
        add(x-1,y);
        add(x,y+1);
        add(x,y-1);
       }
      }
      for (i=1;i<=n;i++)
      {
       for (j=1;j<=m;j++)
        if (a[i][j]==0) cout << "-"; else
        if (a[i][j]==2) cout << "B"; else
        if (a[i][j]==3) cout << "W";
        cout << endl;
       }
    return 0;
}