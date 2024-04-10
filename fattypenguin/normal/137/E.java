import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	int n;
	boolean v[];

	class Pair implements Comparable<Pair>
	{
		int v,w;
		public Pair(int v,int w)
		{
			this.v = v;
			this.w = w;
		}
		@Override
		public int compareTo(Pair o) {
			if (v != o.v) return v - o.v;
			return w - o.w;
		}
	}
	
    private void solve() throws IOException {
    	v = new boolean[256];
    	Arrays.fill(v,false);
    	v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = true;
    	v['A'] = v['E'] = v['I'] = v['O'] = v['U'] = true;
    	String s = nextToken();
    	n = s.length();
    	Pair w[] = new Pair[n+1];
    	int now = 0;
    	w[0] = new Pair(0,0);
    	for (int i = 0;i < n;++i)
    	{
    		if (v[s.charAt(i)])
    			++now;
    		w[i+1] = new Pair(2*(i+1) - 3*now, i+1);
    	}
    	Arrays.sort(w);
    	Pair answer = new Pair(0,1);
    	int mini = Integer.MAX_VALUE;
    	for (int i = 0;i <= n;++i)
    	{
    		if (mini < w[i].w)
    		{
    			if (w[i].w - mini > answer.v)
    				answer = new Pair(w[i].w - mini,0);
    			if (w[i].w - mini == answer.v)
    				++answer.w;
    		}
    		mini = Math.min(mini,w[i].w);
    	}
    	if (answer.v == 0)
    		writer.println("No solution");
    	else writer.println(answer.v + " " + answer.w);
    }

    public static void main(String[] args) {
        new Main().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}