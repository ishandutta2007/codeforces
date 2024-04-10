#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int _,n;
map <int,int> f;
int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        f.clear();
        for (int i=0;i<n;i++){
            int x;scanf("%d",&x);
            f[-x]++;
        }
        int a=0,b=0,c=0;
        for (auto x:f){
            if (a==0) a+=x.S;
            else if (b<=a) b+=x.S;
            else if (c<=a||a+b+c+x.S<=n/2) c+=x.S;
            else break;
        }
        if (b>a&&c>a&&a+b+c<=n/2) printf("%d %d %d\n",a,b,c);
        else printf("0 0 0\n");
    }
    return 0;
}