#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>

using namespace std;

char f[102][102];
int d[28][102][102];
int wx[26],wy[26];
pair <int,int> q[10002];
int dx[]={-1,0,0,1},
dy[]={0,-1,1,0};

void fill(int n,int m,int t,int X,int Y) {
    int inf=1000000000;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            d[t][i][j]=inf;
    int qs=0;
    q[qs++]=make_pair(X,Y);
    d[t][X][Y]=0;
    for(int i=0;i<qs;++i) {
        int x=q[i].first,y=q[i].second;
        for(int e=0;e<4;++e) {
            int nx=x+dx[e],ny=y+dy[e];
            if (nx>=0&&nx<n&&ny>=0&&ny<m&&d[t][nx][ny]==inf&&f[nx][ny]!='#') {
                d[t][nx][ny]=d[t][x][y]+(f[x][y]>='0'&&f[x][y]<='9' ? f[x][y]-'0' : 1);
                q[qs++]=make_pair(nx,ny);
            }
        }
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d\n",&n,&m,&k);
    for(int i=0;i<n;++i)
        gets(f[i]);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if (f[i][j]>='a'&&f[i][j]<='z')
                wx[f[i][j]-'a']=i,wy[f[i][j]-'a']=j;
    for(int t=0;t<26;++t) {
        fill(n,m,t,wx[t],wy[t]);
    }
    int cx,cy,fx,fy;
    string s;
    cin >> cx >> cy >> s >> fx >> fy;
    --cx; --cy; --fx; --fy;
    fill(n,m,26,cx,cy);
    vector < pair <int,int> > v,v1;
    v.push_back(make_pair(cx,cy));
    for(int i=0;i<s.size();++i) {
        int arr=0;
        fill(n,m,0,cx,cy);
        int x=wx[s[i]-'a'],y=wy[s[i]-'a'];
        for(int ii=0;ii<n;++ii)
            for(int jj=0;jj<m;++jj)
                if (f[ii][jj]==s[i]&&d[0][x][y]>d[0][ii][jj]) {
                    x=ii; y=jj;
                }
        if (d[arr][x][y]<=k) {
            k-=d[arr][x][y];
            cx=x; cy=y;
        } else {
            fx=x; fy=y;
            break;
        }
    }
//  cout << k << "  " << cx << "    " << cy << endl;
    fill(n,m,27,fx,fy);
    while(k>0) {
        for(int e=0;e<4;++e) {
            int nx=cx+dx[e],ny=cy+dy[e];
            if (nx>=0&&nx<n&&ny>=0&&ny<m&&d[27][nx][ny]==d[27][cx][cy]-(f[nx][ny]>='0'&&f[nx][ny]<='9' ? f[nx][ny]-'0' : 1)) {
                if (k>=(f[cx][cy]>='0'&&f[cx][cy]<='9' ? f[cx][cy]-'0' : 1)) {
                    k-=(f[cx][cy]>='0'&&f[cx][cy]<='9' ? f[cx][cy]-'0' : 1);
                    cx=nx; cy=ny;
                } else k=0;
                break;
            }
        }
        if (cx==fx&&cy==fy) break;
    }
    cout << cx+1 << " " << cy+1 << endl;
    return 0;
}