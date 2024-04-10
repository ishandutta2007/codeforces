#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct point{
    int a,b,c;
    int index;
    point (int x,int y,int z,int in){
        a=x;
        b=y;
        c=z;
        index=in;
    }
};
int n;
vector<point> p;
bool taken[50005];
int main(){
    scanf("%d",&n);
    int a,b,c;
    for (int x=0;x<n;x++){
        scanf("%d%d%d",&a,&b,&c);
        p.push_back(*new point(a,b,c,x+1));
    }
    sort(p.begin(),p.end(),[](point& i,point &j){
        if (i.c!=j.c) return i.c<j.c;
        if (i.b!=j.b) return i.b<j.b;
        return i.a<j.a;
    });
    memset(taken,false,sizeof(taken));
    for (int x=1;x<p.size();x++){
        if (p[x-1].b==p[x].b && p[x-1].c==p[x].c){
            printf("%d %d\n",p[x-1].index,p[x].index);
            taken[x-1]=true;
            taken[x]=true;
            x++;
        }
    }
    vector<point> temp;
    for (int x=0;x<p.size();x++){
        if (!taken[x]) temp.push_back(p[x]);
    }
    p=temp;
    memset(taken,false,sizeof(taken));
    for (int x=1;x<p.size();x++){
        if (p[x-1].c==p[x].c){
            printf("%d %d\n",p[x-1].index,p[x].index);
            taken[x-1]=true;
            taken[x]=true;
            x++;
        }
    }
    temp.clear();
    for (int x=0;x<p.size();x++){
        if (!taken[x]) temp.push_back(p[x]);
    }
    p=temp;
    for (int x=1;x<p.size();x+=2){
        printf("%d %d\n",p[x-1].index,p[x].index);
    }
}