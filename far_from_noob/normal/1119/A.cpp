#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans1,ans2;
    for(int i=n-1;i>0;i--){
        if(a[i]!=a[0]){
            ans1=i;
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[n-1]){
            ans2=n-1-i;
            break;
        }
    }
    //cout << "fuck";
    if(ans1>=ans2)cout << ans1;
    else cout<< ans2;
    return 0;
}