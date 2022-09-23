#include <iostream>
using namespace std;
int main()
{
    int a1,b1,a[101],b[101],i,cnt=-1,mina=99999,minb=99999,maxa=0,maxb=0;
    cin>>a1>>b1;
    for( i=1; i<=a1; i++ ){
        cin>>a[i];
        mina=min(mina,a[i]);
        maxa=max(maxa,a[i]);
    }
    for( i=1; i<=b1; i++ ){
        cin>>b[i];
        minb=min(minb,b[i]);
        maxb=max(maxb,b[i]);
    }
    for( i=maxa; i<minb; i++ ){
        cnt=i;
        if( cnt>=2*mina ){
            break;
        }
        else{
            cnt=-1;
        }
    }
    cout<<cnt;
    return 0;
}