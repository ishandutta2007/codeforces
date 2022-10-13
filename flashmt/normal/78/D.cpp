#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

ll re,r;

ll sqr(ll x) { return x*x; }

int out(int i,int j)
{
    if (sqr(3LL*i+1)+sqr(2LL*j+i%2+1)*3>r) return 1;
    if (sqr(3LL*i+2)+sqr(2LL*j+i%2)*3>r) return 1;
    return 0;
}

int main()
{
    int i,j;
    cin >> r;
    i=0; j=r;
    r*=r*4;
    while (1)
    {
       while (j>=0 && out(i,j)) j--;
       if (j<0) break;
       re+=(j*2+1+i%2)*(i==0?1:2);
       if (i%2) j++;
       i++;
    }
    cout << re << endl;
    return 0;
}