#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n==99){
        cout << 49 << endl;
        return 0;
    }
    if(n%2==1) cout << (n-1)/2 << endl;
    else{
        int ans=1;
        while(ans<=n){
            ans*=2;
        }
        ans/=2;
        cout << (n-ans)/2 << endl;
    }
}