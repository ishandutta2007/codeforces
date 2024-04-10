import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;
import java.util.function.IntConsumer;

public class Problem2A {

	String readWord(BufferedReader in) throws IOException {

		StringBuilder b = new StringBuilder();
		int c = 0;
		while (true) {
			c = in.read();
			if (c < 0) {
				return "";
			}
			if (c > ' ') {
				break;
			}
		}
		while (true) {
			b.append((char) c);
			c = in.read();
			if (c <= ' ') {
				break;
			}
		}
		return b.toString();
	}
	
	Map<String, Integer> finalScores;
	
	Map<String, Integer> calcFinalScores(String[] names, int[] scores) {
		Map<String, Integer> curScores = new HashMap<>();
		for (int i = 0; i < scores.length; i++) {
			if (!curScores.containsKey(names[i])) {
				curScores.put(names[i], scores[i]);
			} else {
				curScores.put(names[i], curScores.get(names[i]) + scores[i]);
			}
		}
		return curScores;
	}
	
	public String calcWinner(String[] names, int[] scores, int maxScore, Function<String, Boolean> filter) {
		Map<String, Integer> curScores = new HashMap<>();
		for (int i = 0; i < scores.length; i++) {
			int value = 0; 
			if (curScores.containsKey(names[i])) {
				value = curScores.get(names[i]);
			}
			value += scores[i];
			if (value >= maxScore && filter.apply(names[i])) {
				return names[i];
			}
			curScores.put(names[i], value);
		}
		throw new RuntimeException();
	}

	public void run(BufferedReader in, PrintWriter out) throws IOException {
		int n = Integer.parseInt(readWord(in));
		String[] names = new String[n];
		int[] scores = new int[n];
		for (int i = 0; i < n; i++) {
			names[i] = readWord(in);
			scores[i] = Integer.parseInt(readWord(in));
		}
		Map<String, Integer> finalScores = calcFinalScores(names, scores);
		final int[] maxScore = { 0 };
		finalScores.forEach((name, score) -> maxScore[0] = Math.max(
				maxScore[0], score));
		String winner = calcWinner(names, scores, maxScore[0],
				name -> finalScores.get(name) == maxScore[0]);
		out.println(winner);
	}

	public static void main(String[] args) {
		try (
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out))
		) {
			new Problem2A().run(in, out);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}