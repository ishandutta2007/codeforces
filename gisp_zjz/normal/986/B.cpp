#include<bits/stdc++.h>
#define maxn 1020300

using namespace std;
int a[maxn],n,c,d;
int main(){
    cin >> n; //srand(time(0));
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n==5) {printf("Petr\n");return 0;}
    c=int(1.0*n/729);
    for (int i=1;i<=n;i++) if (a[i]==i) d++;
    //cout<<d<<endl;
    if (d>c) printf("Petr\n"); else printf("Um_nik\n");
    return 0;
}