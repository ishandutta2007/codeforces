#include <cstdio>  
#include <map>  
#include <utility>  
#include <cstring>  
  
using namespace std;  
  
const int dir[8][2]={{-1,-1},{1,1},{-1,1},{1,-1},{0,-1},{-1,0},{1,0},{0,1}};  
  
struct Node {  
    int fe,v;  
};  
struct Edge {  
    int t,ne;  
};  
  
map<pair<int,int>,int> c;  
Node a[100100];  
int que[100100];  
Edge b[800100];  
int n,p;  
  
void putedge(int x,int y) {  
    b[p].t=y;  
    b[p].ne=a[x].fe;  
    a[x].fe=p++;  
}  
  
void bfs(int s,int t) {  
    int p=0,q=0,i,j;  
    que[q++]=s;  
    a[s].v=0;  
    while (p!=q) {  
        i=que[p++];  
        for (j=a[i].fe;j!=-1;j=b[j].ne) {  
            if (a[b[j].t].v==-1) {  
                a[b[j].t].v=a[i].v+1;  
                que[q++]=b[j].t;  
            }  
        }  
    }  
}  
  
int main() {  
    int nn,i,x,y,z,j;  
    int x0,y0,x1,y1;  
    n=1;  
    memset(a,-1,sizeof(a));  
    p=0;  
    scanf("%d%d%d%d",&x0,&y0,&x1,&y1);  
    c[make_pair(x0,y0)]=n++;  
    c[make_pair(x1,y1)]=n++;  
    scanf("%d",&nn);  
    for (i=0;i<nn;i++) {  
        scanf("%d%d%d",&x,&y,&z);  
        for (j=y;j<=z;j++) {  
            if (c[make_pair(x,j)]==0) c[make_pair(x,j)]=n++;  
        }  
    }  
    for (map<pair<int,int>,int>::iterator it=c.begin();it!=c.end();it++) {  
        i=it->second;x=it->first.first;y=it->first.second;    
        for (j=0;j<8;j++) {  
            map<pair<int,int>,int>::iterator it2=c.find(make_pair(x+dir[j][0],y+dir[j][1]));  
            if (it2!=c.end()) putedge(i,it2->second);  
        }  
    }  
    bfs(1,2);  
    printf("%d\n",a[2].v);  
    return 0;  
}