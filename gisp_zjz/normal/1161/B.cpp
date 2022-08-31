#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
const int maxn=505050;
int n,ans,m,p[maxn];
set <pi> s;
bool check(int x){
    for (auto p:s){
        int u=(p.first+x)%n;
        int v=(p.second+x)%n;
        if (u>v) swap(u,v);
        if (s.find((pi){u,v})==s.end()) return 0;
    }
    return 1;
}
int main(){
    for (int i=2;i<maxn;i++) if (!p[i])
        for (int j=2;j*i<maxn;j++) p[i*j]=1;
    scanf("%d%d",&n,&m);
    while (m--){
        int u,v;
        scanf("%d%d",&u,&v);
        u--; v--;
        if (u>v) swap(u,v);
        s.insert((pi){u,v});
    }
    for (int i=2;i<maxn;i++) if (!p[i]&&n%i==0){
        if (check(n/i)) {puts("Yes");return 0;}
    }
    puts("No");
    return 0;
}