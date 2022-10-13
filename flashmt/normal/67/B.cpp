#include<iostream>
#include<algorithm>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int n,k,a[1111],b[1111],d[1111];

int main()
{
    int i,j;
    cin >> n >> k;
    fr(i,1,n) cin >> b[i];
    fr(i,1,n)
    {
      fr(j,1,n)
        if (!d[j] && !b[j]) break;
      a[i]=j; d[j]=1;
      fr(j,1,n)
        if (!d[j] && j+k<=a[i]) b[j]--;
    }    
    fr(i,1,n) cout << a[i] << " ";
    cout << endl;
    //system("pause");
    return 0;
}