#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
int x,y,_,n,xx,yy;

int main(){
    cin >> _;
    while (_--){
        cin >> n;
        x=0; y=0;
        bool flag=1;
        while (n--){
            cin >> xx >> yy;
            xx-=x; yy-=y;
            x+=xx; y+=yy;
            if (xx<yy||yy<0) flag=0;
        }
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}