#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int,int> arr;

void pre(){
    arr[3] = 1;
    arr[7] = 1;
    arr[15] = 5;
    arr[31] = 1;
    arr[63] = 21;
    arr[127] = 1;
    arr[255] = 85;
    arr[511] = 73;
    arr[1023] = 341;
    arr[2047] = 89;
    arr[4095] = 1365;
    arr[8191] = 1;
    arr[16383] = 5461;
    arr[32767] = 4681;
    arr[65535] = 21845;
    arr[131071] = 1;
    arr[262143] = 87381;
    arr[524287] = 1;
    arr[1048575] = 349525;
    arr[2097151] = 299593;
    arr[4194303] = 1398101;
    arr[8388607] = 178481;
    arr[16777215] = 5592405;
    arr[33554431] = 1082401;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    pre();

    int x, q;
    cin>>q;
    while(q--){
        cin>>x;
        if(arr.find(x) == arr.end()){
            while(true){
                if((x&(x-1)) == 0)break;
                x &= (x-1);
            }
            x <<= 1;
            x -= 1;
            cout<<x<<endl;
        }else{
            cout<<arr[x]<<endl;
        }
    }

}