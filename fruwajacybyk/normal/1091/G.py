import math;
import random;

n = int(input());

res = [n];

for i in range(1,50):
    m = random.randint(1,n-1);
    x = (m*m) % n;
    print ("sqrt", x);
    y = int(input());
    z = max(y-m,m-y);
    p = math.gcd(n,z)%n;
    if (p != 0) :
        res2 = [];
        for x in res :
            d = math.gcd(x, p);
            e = x//d;
            if (d!= 1 and e!=1) :
                res2.append(d); 
                res2.append(e);
            else :
                res2.append(x);
        res = res2;

res.sort();
print ("!", len(res), " ".join([str(x) for x in res]));