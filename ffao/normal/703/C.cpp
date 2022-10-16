    #include<bits/stdc++.h>
    using namespace std;
    main()
    {
    int i,n;
    double u,v,w;
    cin>>n>>w>>v>>u;
    double x,y,l=1e9+7,r=0;
    for(i=0;i<n;i++)
    {
    cin>>x>>y;
    l=min(l,x-y/u*v);
    r=max(r,x-y/u*v);
    }
    cout<<fixed<<setprecision(6)<<w/u+r/v*(l<0);
    }