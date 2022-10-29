#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
struct node{
    int l,r;
    int sig;
}a[N];
int n;
bool cmp(const node&a,const node&b){
    return a.r<b.r||(a.r==b.r&&a.l>b.l);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i].l>>a[i].r,a[i].sig=i;
    sort(a+1,a+n+1,cmp);
    int x=1,y=0;
    for (int i=2;i<=n;i++){
        if (a[x].l>=a[i].l){
            y=i;
            break;
        }
        x=i;
    }
    y==0?cout<<"-1 -1":cout<<a[x].sig<<' '<<a[y].sig;
    return 0;
}