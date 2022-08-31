#include<bits/stdc++.h>
using namespace std;
int a[123456],A,B,C,D;

int main(){
    cin >> A >> B >> C >> D;
    if (abs(A+C-B-D)>1){puts("NO");return 0;}
    int n=A+B+C+D;
    if (A+C>=B+D){
        for (int i=0;i<A;i++) a[i*2]=0;
        for (int i=A;i<A+C;i++) a[i*2]=2;
        for (int i=0;i<B;i++) a[i*2+1]=1;
        for (int i=B;i<B+D;i++) a[i*2+1]=3;
        bool flag=1;
        for (int i=0;i<n-1;i++) if (abs(a[i]-a[i+1])>1) flag=0;
        if (flag){
            puts("YES");
            for (int i=0;i<n;i++) printf("%d ",a[i]); puts("");
            return 0;
        }
    }
    if (B+D>=A+C){
        for (int i=0;i<A;i++) a[i*2+1]=0;
        for (int i=A;i<A+C;i++) a[i*2+1]=2;
        for (int i=0;i<B;i++) a[i*2]=1;
        for (int i=B;i<B+D;i++) a[i*2]=3;
        bool flag=1;
        for (int i=0;i<n-1;i++) if (abs(a[i]-a[i+1])>1) flag=0;
        if (flag){
            puts("YES");
            for (int i=0;i<n;i++) printf("%d ",a[i]); puts("");
            return 0;
        }
    }
    puts("NO");
    return 0;
}