#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
char s[105];
bool f[105][105];
int n,m,_;
struct node{
    int a,b,c,d,e,f;
};
vector<node> ans;
void print(){
    cout << ans.size() << endl;
    for (auto x:ans) {
        printf("%d %d %d %d %d %d\n",x.a+1,x.b+1,x.c+1,x.d+1,x.e+1,x.f+1);
    }
}
node w[4]={
    (node){0,0,0,1,1,0},
    (node){0,0,0,1,1,1},
    (node){0,0,1,0,1,1},
    (node){0,1,1,0,1,1}
};
void work(node u){
    ans.pb(u);
    f[u.a][u.b]^=1;
    f[u.c][u.d]^=1;
    f[u.e][u.f]^=1;
}
void clr(int x,int y,int xx,int yy){
    if (x==xx){
        assert(y+1==yy);
        if (f[x][y]&&f[x][y+1]) work((node){x-1,y,x,y,x,y+1});
        else if (f[x][y]) work((node){x-1,y,x-1,y+1,x,y});
        else if (f[x][y+1]) work((node){x-1,y,x-1,y+1,x,y+1});
    } else {
        assert(x+1==xx);
        if (f[x][y]&&f[x+1][y]) work((node){x,y-1,x,y,x+1,y});
        else if (f[x][y]) work((node){x,y-1,x+1,y-1,x,y});
        else if (f[x+1][y]) work((node){x,y-1,x+1,y-1,x+1,y});
    }
}
int id[16];
void init(){
    for (int i=0;i<16;i++){
        memset(f,0,sizeof(f));
        for (int j=0;j<4;j++) if (i&(1<<j)) work(w[j]);
        id[f[0][0]+f[0][1]*2+f[1][0]*4+f[1][1]*8]=i;
    }
}

int main(){
    cin >> _;
    init();
    while (_--){
        cin >> n >> m;
        for (int i=0;i<n;i++){
            cin >> s;
            for (int j=0;j<m;j++) f[i][j]=s[j]=='1';
        }
        ans.clear();
        for (int i=n-1;i>=2;i--)
            for (int j=0;j<m-1;j++)
                clr(i,j,i,j+1);
        for (int j=m-1;j>=2;j--) clr(0,j,1,j);
        int mask=id[f[0][0]+f[0][1]*2+f[1][0]*4+f[1][1]*8];
        for (int j=0;j<4;j++) if (mask&(1<<j)) ans.pb(w[j]);
        print();
    }
    return 0;
}