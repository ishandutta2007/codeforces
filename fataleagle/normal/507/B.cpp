#include <bits/stdc++.h>

using namespace std;

long long R, A, B, C, D;

int main()
{
    cin>>R>>A>>B>>C>>D;
    C-=A;
    D-=B;
    long long ans=ceill(sqrtl(C*C+D*D)/(2*R));
    cout<<ans<<endl;
    return 0;
}