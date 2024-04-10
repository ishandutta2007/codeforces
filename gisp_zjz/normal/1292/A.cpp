#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
bool f[2][555555];
int n,q,res,x,y;
void add(int x,int y){
    for (int offset=-1;offset<=1;offset++) if (f[x^1][y+offset]) res++;
    f[x][y]=1;
}
void del(int x,int y){
    for (int offset=-1;offset<=1;offset++) if (f[x^1][y+offset]) res--;
    f[x][y]=0;
}

int main(){
    cin >> n >> q;
    while (q--){
        cin >> x >> y; x--;
        if (f[x][y]) del(x,y); else add(x,y);
        if (res) puts("No"); else puts("Yes");
    }
    return 0;
}