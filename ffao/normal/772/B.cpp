    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define M 1000000007
    #define INF ((1LL<<62LL) - 1)
     
    #define Point pair<double, double>
    #define F first
    #define S second
     
    // Function to return the minimum distance
    // between a line segment AB and a point E
    double minDistance(Point A, Point B, Point E)
    {
     
        // vector AB
        pair<double, double> AB;
        AB.F = B.F - A.F;
        AB.S = B.S - A.S;
     
        // vector BP
        pair<double, double> BE;
        BE.F = E.F - B.F;
        BE.S = E.S - B.S;
     
        // vector AP
        pair<double, double> AE;
        AE.F = E.F - A.F,
                AE.S = E.S - A.S;
     
        // Variables to store dot product
        double AB_BE, AB_AE;
     
        // Calculating the dot product
        AB_BE = (AB.F * BE.F + AB.S * BE.S);
        AB_AE = (AB.F * AE.F + AB.S * AE.S);
     
        // Minimum distance from
        // point E to the line segment
        double reqAns = 0;
     
        // Case 1
        if (AB_BE > 0) {
     
            // Finding the magnitude
            double y = E.S - B.S;
            double x = E.F - B.F;
            reqAns = sqrt(x * x + y * y);
        }
     
            // Case 2
        else if (AB_AE < 0) {
            double y = E.S - A.S;
            double x = E.F - A.F;
            reqAns = sqrt(x * x + y * y);
        }
     
            // Case 3
        else {
     
            // Finding the perpendicular distance
            double x1 = AB.F;
            double y1 = AB.S;
            double x2 = AE.F;
            double y2 = AE.S;
            double mod = sqrt(x1 * x1 + y1 * y1);
            reqAns = abs(x1 * y2 - y1 * x2) / mod;
        }
        return reqAns;
    }
     
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        int n; cin >> n;
        pair<double,double> a[n];
     
        for(int i=0;i<n;i++){
            cin >> a[i].first >> a[i].second;
        }
     
        double ans = INF;
     
        for(int i=0;i<n;i++){
            auto cur = a[i];
            auto mid = a[(i+1)%n];
            auto last = a[(i+2)%n];
     
            ans = min(ans, minDistance(cur, last, mid)/2.0);
        }
     
        cout << fixed << setprecision(12) <<  ans << "\n";
     
     
     
        
     
    }