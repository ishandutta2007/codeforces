#include <iostream>
#include <string>
using namespace std;
int n;
string arr[500005];

int main(){
    cin>>n;
    for (int x=0;x<n;x++) cin>>arr[x];
    
    for (int x=n-2;x>=0;x--){
        for (int y=0;y<=min(arr[x].size(),arr[x+1].size());y++){
            if (arr[x][y]>arr[x+1][y]){
                arr[x]=arr[x].substr(0,y);
                goto _end;
            }
            
            else if (arr[x][y]<arr[x+1][y]) goto _end;
        }
        
        arr[x]=arr[x].substr(0,arr[x+1].size());
        _end:;
    }
    
    for (int x=0;x<n;x++) cout<<arr[x]<<'\n';
}