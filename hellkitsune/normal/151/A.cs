using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, k, l, c, d, p, nl, np;
            string[] t = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            n = int.Parse(t[0]);
            k = int.Parse(t[1]);
            l = int.Parse(t[2]);
            c = int.Parse(t[3]);
            d = int.Parse(t[4]);
            p = int.Parse(t[5]);
            nl = int.Parse(t[6]);
            np = int.Parse(t[7]);
            int max = ((k * l) / (nl * n));
            int cur = (c * d) / n;
            if (cur < max)
                max = cur;
            cur = p / (np * n);
            if (cur < max)
                max = cur;
            Console.WriteLine(max);
        }
    }
}