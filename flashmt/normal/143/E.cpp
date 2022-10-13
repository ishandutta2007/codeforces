    #include <iostream>
    #include <algorithm>
    #include <cstdio>
    #include <vector>
    #include <cstring>
    #include <string>
    #include <cmath>
    #include <utility>
    #include <map>
    #include <set>
    #include <queue>
    #include <stack>
    #include <sstream>
    #define fr(a,b,c) for (int a=b;a<=c;a++)
    #define frr(a,b,c) for (int a=b;a>=c;a--)
    #define rep(a,b) for (int a=0;a<b;a++)
    #define repp(a,b) for (int a=b-1;a>=0;a--)
    #define pb push_back
    #define mp make_pair
    #define fi first
    #define se second
    #define sz(a) int(a.size())
    #define all(a) a.begin(),a.end()
    #define pii pair<int,int>
    #define oo 1000111222
    #define maxN 1
    using namespace std;
    const int dx[4][4]={{0,0,1,2},{1,1,1,2},{1,2,2,2},{1,1,1,2}};
    const int dy[4][4]={{1,2,1,1},{-2,-1,0,0},{0,-1,0,1},{0,1,2,0}};
    const int dxx[]={-1,0,1,0};
    const int dyy[]={0,1,0,-1};
    const int res[10][10]={{0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,1,1,2,2,3,3,4},
                           {0,0,0,1,2,2,3,4,4,5},
                           {0,0,0,2,2,4,4,5,6,7},
                           {0,0,0,2,3,4,5,6,7,8},
                           {0,0,0,3,4,5,6,8,9,10},
                           {0,0,0,3,4,6,7,9,10,12},
                           {0,0,0,4,5,7,8,10,12,13}};
                           

    int m,n,ans=-1,cnt,a[100][100],A[100][100],border[100][100];

    int ok(int x,int y,int t)
    {
            fr(i,0,3)
            {
                    int xx=x+dx[t][i],yy=y+dy[t][i];
                    if (xx<=0 || yy<=0 || xx>m || yy>n || a[xx][yy]) return 0;
            }
            return 1;
    }

    void att(int x,int y)
    {
            if (x>m)
            {
                    if (cnt>ans)
                    {
                            ans=cnt;
                            fr(i,1,m) fr(j,1,n) A[i][j]=a[i][j];
                            if (ans==res[m][n])
                            {
                                    cout << ans << endl;
                                    fr(i,1,m)
                                    {
                                            fr(j,1,n) cout << (A[i][j]?char(A[i][j]+64):'.');
                                            puts("");
                                    }
                                    exit(0);
                            }
                    }
                    return;
            }
            if (y>n)
            {
                    att(x+1,1);
                    return;
            }
            if (!a[x][y] && border[x][y])
                    fr(t,0,3)
                            if (ok(x,y,t))
                            {
                                    vector <int> X,Y;
                                    a[x][y]=++cnt;
                                    fr(i,0,3)
                                    {
                                            int xx=x+dx[t][i],yy=y+dy[t][i];
                                            a[xx][yy]=cnt;
                                            fr(j,0,3)
                                            {
                                                    int xxx=xx+dxx[j],yyy=yy+dyy[j];
                                                    if (!a[xxx][yyy] && !border[xxx][yyy])
                                                            border[xxx][yyy]=1, X.pb(xxx), Y.pb(yyy);
                                            }
                                    }
                                   
                                    att(x,y+1);
                                   
                                    fr(i,0,3) a[x+dx[t][i]][y+dy[t][i]]=0;
                                    rep(i,sz(X)) border[X[i]][Y[i]]=0;
                                    a[x][y]=0;
                                    --cnt;
                            }
            att(x,y+1);
    }

    int main()
    {
            cin >> m >> n;
            fr(j,1,n) border[1][j]=1;
            att(1,1);
    }