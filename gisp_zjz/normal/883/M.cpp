#include<bits/stdc++.h>

using namespace std;
int a,b,c,d;

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (a==c) cout << 6+abs(d-b)*2 << endl;
    else if (b==d) cout << 6+abs(c-a)*2 << endl;
    else cout << 4+abs(d-b)*2+abs(c-a)*2 << endl;
}