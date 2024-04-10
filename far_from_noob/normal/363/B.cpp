#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int countmin=0,temp,ans=0;
    for(int i=0;i<k;i++){
        countmin+=a[i];
    }
    temp=countmin;
    for(int i=0;i<n-k;i++){
        temp=temp-a[i]+a[i+k];
        if(temp< countmin){
            ans=i+1;
            countmin=temp;
        }
    }
    cout << ans+1;
    //cout << "Hello world!" << endl;
    return 0;
}