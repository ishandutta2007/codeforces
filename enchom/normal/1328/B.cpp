    #include <bits/stdc++.h>
    #define int long long
    #define endl '\n'
    ///Yeah, I am the backupguy!
    using namespace std;
    int32_t main()
    {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin>>testcases;
    for(int x=0;x<testcases;x++){
    int a,b;
    cin>>a>>b;
    b--;
    long double quadratic=(sqrtl(8.0*b+1)-1)/2.0;
    int approx=quadratic;
    int answer=(approx*(approx+1))/2;
    int accurate=round(quadratic*(quadratic+1.0)/2.0);
    for(int i=0;i<a;i++){
    if(i==a-approx-2||(a-i-1==(accurate-answer)))
    cout<<'b';
    else
    cout<<'a';
    }
    cout<<endl;
    }
    return 0;
}