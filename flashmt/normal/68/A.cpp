#include<iostream>
#include<algorithm>
#define fr(a,b,c) for(a=b;a<=c;a++)
using namespace std;

int main()
{
    int i,x,m,a,b;
    cin >> m;
    fr(i,1,3) cin >> x, m=min(m,x);
    cin >> a >> b;
    m=min(m,b+1);
    cout << max(0,m-a) << endl;   
    //system("pause");
    return 0;
}