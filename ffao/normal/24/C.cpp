    #include<iostream>
    #include<cstdio>
    #include<cstring>
    #include<cmath>
    #include<algorithm>
    #include<vector>
    #include<queue>
    #include<stack>
    #include<map>
    #include<set>
    #include<iterator>
    #include<climits>
    #include<functional>
    #include<iomanip>
    using namespace std;
    #define   mx             200007
    #define   LL             long long
    #define   ULL            unsigned long long
    #define   mod            1000000007
    #define   infinity       1000,000,000,000,000,007
    #define   MP             make_pair
    #define   PB             push_back
    #define   endl           "\n"
    #define   IOS            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define   pi             acos(-1.0)
    #define   int            long long
     
    int n,j; pair<int,int>A[mx],M[mx];
     
    int32_t main()
    {
    IOS
     
    cin>>n>>j; cin>>M[0].first>>M[0].second;
     
    for(int i=0;i<n;++i)cin>>A[i].first>>A[i].second;
     
    for(int i=1;i<2*n;++i)
    {
        M[i].first =2*A[(i-1)%n].first -M[i-1].first;
        M[i].second=2*A[(i-1)%n].second-M[i-1].second;
    }
     
    cout<<M[j%(2*n)].first<<" "<<M[j%(2*n)].second<<endl;
     
    	return 0;
    }