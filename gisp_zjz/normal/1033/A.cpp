#include<bits/stdc++.h>
#define maxn 1002

using namespace std;
int n,a,b,c,d,e,f;
int main(){
    cin >> n;
    cin >> a >> b >> c >> d >> e >> f;
    if ((c-a)*(e-a)<0) puts("NO");
    else if ((d-b)*(f-b)<0) puts("NO");
    else puts("YES");
}