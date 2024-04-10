    #include<cstdio>
    #include<cmath>
    #include<iostream>
     
    using namespace std;
     
    long double a1, b1, r1;
    long double a2, b2, r2;
    long double pi = 3.14159265358979323846;
    long double ans;
    long double angle(long double r1, long double dist, long double r2)
    {
    	return acos((r1 * r1 + dist * dist - r2 * r2) / r1 / dist / 2) * 2;
    }
    long double d;
    long double S1()
    {
    	return r1 * r1 * (angle(r1, d, r2) - sin(angle(r1, d, r2))) / 2;
    }
    long double S2()
    {
    	return r2 * r2 * (angle(r2, d, r1) - sin(angle(r2, d, r1))) / 2;
    }
    int main()
    {
    	cin >> a1 >> b1 >> r1;
    	cin >> a2 >> b2 >> r2;
    	if(r2 < r1)
    	{
    		swap(r1, r2);
    	}
    	//cout <<sqrt(0) << endl;
    	 d = sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
    	//printf("%.20Lf %.20Lf %.20Lf %.20Lf\n", a1, a2, b1, b2);
    	ans = 0.0;
    	if(d >= r1 + r2)
    	{
    		
    		printf("%.20Lf\n",ans);
    		return 0;
    	}
    	else if(r1 + d <= r2)
    	{
    		//printf("ok\n");
    		ans = pi * r1 * r1;
    		printf("%.20Lf\n",ans);
    		return 0;
    	}
    	else
    	{
    		//printf("ok\n");
    	    long double ans = S1() + S2(); 
    		printf("%.20Lf", ans);
    	}
    	return 0;
    }