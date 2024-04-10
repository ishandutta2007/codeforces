#include <bits/stdc++.h>

using namespace std;

int n,k,A,B;
vector<long long>p;

long long solve(long long a,long long b) {
    long long beg = lower_bound(p.begin(),p.end(),a) - p.begin();
    long long endik = upper_bound(p.begin(),p.end(),b) - p.begin();
    endik--;
    long long num = endik-beg+1;
    long long power = 0;
    if(num==0) power=A;
    else power = (long long) B*num*(b-a+1);
    if(a==b||num==0) return power;
    return min(power,solve(a,(a+b)/2)+solve((a+b)/2+1,b));
}

int main() {
    cin>>n>>k>>A>>B;
    for(int x,i=0; i<k;i++) {
        cin>>x;
        p.push_back(x);
    }
    sort(p.begin(),p.end());
    cout<<solve(1,pow(2,n));
    return 0;
}