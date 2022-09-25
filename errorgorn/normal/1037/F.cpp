    #include <cstdio>
    #include <stack>
    #include <algorithm>
    using namespace std;
    int n,k;
    long long arr[1000005];
    int left[1000005];
    int right[1000005];
    const int MOD=1000000007;
    long long nums(long long l,long long r){
        long long res=0;
     
        long long l1,l2,m1,m2,r1,r2;
        long long f,b;
     
        l1=1,l2=l-1;
        m1=max(1LL,l),m2=r;
        r1=r+1,r2=l+r;
     
        if (l1<=l2){
            f=((l1-1)/k+1)*k;
            b=l2/k*k;
            if (f<=b){
                //printf("debug: %lld %lld\n",f,b);
                b=(b-f)/k+1;
                res=(res+(f+1)*b+k*(b*(b-1)/2)%MOD)%MOD;
            }
        }
        if (m1<=m2){
            res=(res+(l+1)*(m2/k-(m1-1)/k))%MOD;
        }
        if (r1<=r2){
            f=((r1-1)/k+1)*k;
            b=r2/k*k;
            if (f<=b){
                f=l+r-f;
                b=l+r-b;
                swap(f,b);
                //printf("debug: %lld %lld\n",f,b);
                b=(b-f)/k+1;
                res=(res+(f+1)*b+k*(b*(b-1)/2)%MOD)%MOD;
            }
        }
     
        return res;
    }
    int main(){
        scanf("%d%d",&n,&k);k--;
        for (int x=0;x<n;x++) scanf("%lld",&arr[x]);
     
        stack<int> s;
        for (int x=0;x<n;x++){
            while (!s.empty() && arr[s.top()]<arr[x]){
                right[s.top()]=x-1;
                s.pop();
            }
            s.push(x);
        }
        while (!s.empty()) right[s.top()]=n-1,s.pop();
     
        for (int x=n-1;x>=0;x--){
            while (!s.empty() && arr[s.top()]<=arr[x]){
                left[s.top()]=x+1;
                s.pop();
            }
            s.push(x);
        }
        while (!s.empty()) left[s.top()]=0,s.pop();
     
        long long ans=0;
        int l,r;
        for (int x=0;x<n;x++){
            l=x-left[x];
            r=right[x]-x;
            if (l>r) swap(l,r);
     
            ans=(ans+arr[x]*nums(l,r))%MOD;
        }
     
        printf("%lld\n",ans);
    }