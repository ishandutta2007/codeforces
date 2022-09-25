#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

bool cmp(int i,int j){
    cout<<"? "<<i<<" "<<j<<endl;
    char c;
    cin>>c;
    return c=='>';
}

int main(){
    int TC;
    cin>>TC;
    while (TC--){
        cin>>n;
        vector<int> A,B;
        for (int x=1;x<=n-1;x++){
            A.push_back(x);
        }
        for (int x=n+1;x<=2*n-1;x++){
            B.push_back(x);
        }

        sort(A.begin(),A.end(),cmp);

        sort(B.begin(),B.end(),cmp);

        if (cmp(A.back(),B.back())){
            B.pop_back();
            B.push_back(n);
            sort(B.begin(),B.end(),cmp);
        }
        else{
            A.pop_back();
            A.push_back(n);
            sort(A.begin(),A.end(),cmp);
        }

        if (cmp(A.back(),B.back())){
            B.pop_back();
            B.push_back(2*n);
            sort(B.begin(),B.end(),cmp);
        }
        else{
            A.pop_back();
            A.push_back(2*n);
            sort(A.begin(),A.end(),cmp);
        }
        
        
        int AA=A[1];
        int BB=B[1];
        while (A.size()>1 && B.size()>1){
            if (cmp(A.back(),B.back())){
                B.pop_back();
            }
            else{
                A.pop_back();
            }
        }

        while (A.size()>1){
            cmp(A.back(),BB);
            A.pop_back();
        }
        while (B.size()>1){
            cmp(AA,B.back());
            B.pop_back();
        }

        cout<<"!"<<endl;
    }
}