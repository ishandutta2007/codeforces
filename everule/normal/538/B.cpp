#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> ans;
    vector<int> digits;
    while(n){
        digits.push_back(n%10);
        n/=10;
    }
    int c = *max_element(digits.begin(), digits.end());
    cout<<c<<"\n";
    for(int i=0;i<c;i++){
        int val = 0;
        int p10 = 1;
        for(auto &d : digits){
            if(d) val+=p10, --d;
            p10*=10;
        }
        cout<<val<<" ";
    }
}