#include<bits/stdc++.h>
#define maxn 100

using namespace std;
struct node{
    int x,y;
    void print(){
        printf("%c%c-%c%c\n",'a'+x%8,'1'+x/8,'a'+y%8,'1'+y/8);
    }
};
int a[maxn],cnt,n,res,pre[maxn];
int px[8]={1,2,2,1,-1,-2,-2,-1};
int py[8]={2,1,-1,-2,-2,-1,1,2};
bool vis[maxn];
node ans[2000];
char s[3];

int valid(int x,int y){
    if (x<0||x>=8||y<0||y>=8) return -1;
    int tmp=x+y*8;
    if (vis[tmp]) return -1; else return tmp;
}

void mv(int x,int y){
    if (x==y) return;
    memset(vis,0,sizeof(vis));
    queue <int> q; q.push(x);
    while (!q.empty()){
        int u=q.front(),v; q.pop();
        int xx=u%8,yy=u/8;
        for (int o=0;o<8;o++){
            int v=valid(xx+px[o],yy+py[o]);
            if (v==-1) continue;
            pre[v]=u; vis[v]=true;
            q.push(v);
        }
    }
    vector <node> ret; int t=y;
    while (y!=x){
        ret.push_back((node){pre[y],y});
        y=pre[y];
    }
    for (int i=ret.size()-1;i>=0;i--){
        if (a[ret[i].x]&&!a[ret[i].y]){
            ans[cnt++]=ret[i];
            a[ret[i].x]=0;
            a[ret[i].y]=1;
        } else {
            mv(ret[i].y,t);
            ans[cnt++]=ret[i];
            a[ret[i].x]=0;
            a[ret[i].y]=1;
            break;
        }
    }
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s;
        a[s[0]-'a'+(s[1]-'1')*8]=1;
    }
    for (int i=0;i<n;i++)
        for (int j=i;j<64;j++)
            if (a[j]) {mv(j,i); break;}
    cout << cnt << endl;
    for (int i=0;i<cnt;i++) ans[i].print();
}