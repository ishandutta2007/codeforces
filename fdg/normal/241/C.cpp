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

int arr[50005];

struct item{
    item() {};
    item(int v,int y,int xl,int xr,int num) : v(v), y(y), xl(xl), xr(xr), num(num) {};
    int v,y,xl,xr,num;
};

item mir[25203];
int cnt=0;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int hl,hr,n;
    scanf("%d%d%d\n",&hl,&hr,&n);
    int v,l,r; char c;
    for(int t=0;t<n;++t) {
        scanf("%d %c %d %d\n",&v,&c,&l,&r);
        if (c=='T') {
            for(int i=0;i<=102;++i) {
                mir[cnt++]=item(v,100+i*200,l,r,t);
            }
            for(int i=0;i>=-102;--i) {
                mir[cnt++]=item(v,-100+i*200,l,r,t);
            }
        } else {
            for(int i=0;i<=102;++i) {
                mir[cnt++]=item(v,i*200,l,r,t);
            }
            for(int i=1;i<=102;++i) {
                mir[cnt++]=item(v,-i*200,l,r,t);
            }
        }
    }
    int ans=0,cur=hr;
/*  for(int i=1;i<=102;++i) {
        int my=0;
        int was[102]={0},ok=true;
        for(int j=0;j<cnt;++j) {
            bool in=true;
            if (1LL*(mir[j].y-hl)*100000<1LL*mir[j].xl*(cur-hl)) in=false;
            if (1LL*(mir[j].y-hl)*100000>1LL*mir[j].xr*(cur-hl)) in=false;
            if (in) {
                if (was[mir[j].num]) {
                    ok=false;
                    break;
                }
                was[mir[j].num]=true;
                my+=mir[j].v;
            }
        }
        if (ok) ans=max(ans,my);
        cur=2*i*100-cur;
    }*/
    for(int i=1;i<=102;++i) {
        int my=0;
        int was[102]={0},ok=true,tot=0;
        for(int j=0;j<cnt;++j) {
            bool in=true;
            if (1LL*(mir[j].y-hl)*100000*((cur-hl)<0 ? -1 : 1)<1LL*mir[j].xl*(cur-hl)*((cur-hl)<0 ? -1 : 1)) in=false;
            if (1LL*(mir[j].y-hl)*100000*((cur-hl)<0 ? -1 : 1)>1LL*mir[j].xr*(cur-hl)*((cur-hl)<0 ? -1 : 1)) in=false;
            if (in) {
                if (was[mir[j].num]) {
                    ok=false;
                    break;
                }
                ++tot;
                was[mir[j].num]=true;
                my+=mir[j].v;
            }
        }
        if (ok&&tot==(i-1)) ans=max(ans,my);
        cur=2*(i*100)-cur;
    }
    cur=-hr;
    for(int i=0;i<102;++i) {
        int my=0;
        int was[102]={0},ok=true,tot=0;
        for(int j=0;j<cnt;++j) {
            bool in=true;
//          long long v1=1LL*(mir[j].y-hl)*100000*((cur-hl)<0 ? -1 : 1),v2=1LL*mir[j].xl*(cur-hl)*((cur-hl)<0 ? -1 : 1);
//          v1=1LL*(mir[j].y-hl)*100000*((cur-hl)<0 ? -1 : 1),v2=1LL*mir[j].xr*(cur-hl)*((cur-hl)<0 ? -1 : 1);
            if (1LL*(mir[j].y-hl)*100000*((cur-hl)<0 ? -1 : 1)<1LL*mir[j].xl*(cur-hl)*((cur-hl)<0 ? -1 : 1)) in=false;
            if (1LL*(mir[j].y-hl)*100000*((cur-hl)<0 ? -1 : 1)>1LL*mir[j].xr*(cur-hl)*((cur-hl)<0 ? -1 : 1)) in=false;
            if (in) {
                if (was[mir[j].num]) {
                    ok=false;
                    break;
                }
                ++tot;
                was[mir[j].num]=true;
                my+=mir[j].v;
            }
        }
        if (ok&&tot==(i+1)) {
            ans=max(ans,my);
//          cout << cur << "    " << my << endl;
        }
        cur=-(2*((i+1)*100)+cur);
    }
    printf("%d\n",ans);
    return 0;
}