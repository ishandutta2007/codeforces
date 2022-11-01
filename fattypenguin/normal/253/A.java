import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskA implements Runnable {

    private void solve() throws IOException {
    	int n = nextInt();
    	int m = nextInt();
    	String s = "BG";
    	
    	if (n < m) {
    		int t = n;
    		n = m;
    		m = t;
    		
    		s = "GB";
    	}
    	for (int i = 0; i < m; ++i) {
    		writer.print(s);
    	}
    	
    	for (int i = 0; i < n - m; ++i) {
    		writer.print(s.charAt(0));
    	}
    	
    	writer.println();
    }

    public static void main(String[] args) {
        new TaskA().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            tokenizer = null;
            writer = new PrintWriter(new FileWriter("output.txt"));
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