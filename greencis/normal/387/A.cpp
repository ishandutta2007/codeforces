#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,q1,q2;
    char z;
    cin>>a>>z>>b>>c>>z>>d;
    q1 = a*60 + b;
    q2 = c*60 + d;
    if (q1 < q2) q1 += 24*60;
    q1-=q2;
    cout << (q1/60/10) << (q1/60%10) << ":" << (q1%60/10) << (q1%60%10);
    return 0;
}